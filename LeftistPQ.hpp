/**
 * Leftist Priority Queue
 * 
 * Written in C++ for Datastructures and Algorithms (CS 2420) by Josh Jeppson
 * Sorry Dr. Allen, but I really like C++ over Java.
 * 
 * You'll find a Java version, but I really prefer C++
 * */

#ifndef LEFTISTPQ_HPP
#define LEFTISTPQ_HPP

#include <vector>
#include <iostream>
#include <ostream>
#include <sstream>

template <typename T>
class LeftistPQ
{
    /**
     * Nested node class
     * */
    public:
    class Node
    {
        typedef T outer;
        public:
            /**
             * Constructor. Automatically calculates null path length
             * */
            Node(T nData, Node* nLeft = nullptr, Node* nRight = nullptr) :
                data(nData),
                left(nLeft),
                right(nRight)
            { 
                recalculateNPL();
            }
            std::string toString() {
                std::ostringstream oss;
                oss << data << "(" << npl << ")";
                return oss.str();
            }
            /**
             * Recalculates null path length.
             * */
            void recalculateNPL() {
                npl = std::min(nPath(left), nPath(right)) + 1;
            }
            /**
             * Returns if the node is correcly leftist
             * */
            bool leftist() {
                return nPath(left) > nPath(right);
            }
            /**
             * Swaps the kids
             * */
            void swapKids() {
                Node* tmp = left;
                left = right;
                right = tmp;
            }
            /**
             * Datamembers. These can be public, as this is a nested class.
             * */
            Node* left;
            Node* right;
            T data;
            int npl; // Null path length
             /**
             * Overloaded operators. Don't really know if I needed all of these,
             * but I was missing them. (You don't have this in Java :( )
             * */

            bool operator== (const Node& a) {
                return a.data == this.data;
            }
            bool operator!= (const Node& a) {
                return !(a == this);
            }
            bool operator< (const Node& a) {
                return this.data < a.data;
            }
            bool operator> (const Node& a) {
                return this > a;
            }
            bool operator<= (const Node& a) {
                return !(this > a);
            }
            bool operator>= (const Node& a) {
                return !(this < a);
            }
            /**
             * To String method for node
             * */
            std::ostream& operator<< (std::ostream &strm) {
                return strm << data << '(' << npl << ')';
            }
        private:
            /**
             * Wrapper function to get null path length of a certain node (or null)
             * */
            int nPath(Node* r) {
                if (!r) {   // If r is null
                    return -1;
                }
                else {
                    return r->npl;
                }
            }
    };
    public:
        /**
         * Constructor. Sets root to nullptr
         * */
        LeftistPQ() {
            this->root = nullptr;
        }
        /**
         * Destructor. Deletes everything below the root, including root
         * */
        ~LeftistPQ() {
            deleteBelow(this->root);
        }
        /**
         * Removes the smallest node (the root) and merges its two children
         * */
        T deleteMin() {
            if (!root) {
                return nullptr;
            }
            Node tmp = this->root;
            T rValue = tmp->data;
            this->root = merge(root->left, root->right);
            delete tmp;
            return rValue;
        }
        /**
         * Takes T data and merges the two heaps (one of which is of size 1).
         * Assumes that T has overriden comparison operators
         */
        void insert(T data) {
            Node* node = new Node(data);
            this->root = merge(root, node);
        }
        /**
         * buildString method, wrapper for private std::string buildString(Node*, int)
         * */
        std::string buildString() {
            return buildString(root, 0);
        }
    private:
        /**
         * Builds string for tree below root r
         * */
        std::string buildString(Node* r, int level) {
            if (r == nullptr) {
                return "";
            }
            std::string s = "";
            std::string spaces = "";
            for (int i = 0; i < level; i++) {
                spaces += "  ";
            }
            s += spaces + buildString(r->left, level + 1) + '\n';
            s += spaces + r->toString();
            s += spaces + buildString(r->right, level + 1);
            return s;

        }
        /**
         * Deletes all nodes below a certain node. For memory management
         * purposes.
         * */
        void deleteBelow(Node* r) {
            if (!r) {
                return;
            }
            else {
                deleteBelow(r->left);
                deleteBelow(r->right);
                delete r;
                return;
            }
        }
        /**
         * Takes two roots and merges them downward.
         * */
        Node* merge (Node* r1, Node* r2) {
            if (!r1) {
                return r2; 
            }
            if (!r2) {
                return r1;
            }
            Node* small;
            if (r1 < r2) {
                r1->right = merge(r1->right, r2);
                small = r1;
            }
            else {
                r2->right = merge(r2->right, r1);
                small = r2;
            }
            // Do swaps and update null path length
            small->recalculateNPL();
            if (!small->leftist()) {
                small->swapKids();
            }
            return small;
        }
        /**
         * Updates all null path lengths below a node.
         * */
        void updateNPRS(Node* r) {
            if (!r) {
                return;
            }
            updateNPRS(r->left);
            updateNPRS(r->right);
            r->recalculateNPR();
        }

        /**
         * Root data member
         * */
        Node* root;
        std::vector<std::string>* pVector;

};

/**
 * To String method--makes a string from the tree and returns it.
 * */
template <typename T>
std::ostream& operator<<(std::ostream &strm, LeftistPQ<T> &a) {
    return strm << a.buildString();
}

#endif // LEFTISTPQ_HPP