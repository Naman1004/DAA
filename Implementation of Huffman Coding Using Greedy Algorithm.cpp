#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

// A tree node
struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char ch, int freq) {
        left = right = nullptr;
        this->ch = ch;
        this->freq = freq;
    }
};

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Print the Huffman codes
void printCodes(struct Node* root, string str) {
    if (!root)
        return;

    if (root->ch != '$')
        cout << root->ch << ": " << str << "\n";

    printCodes(root->left, str + "0");
    printCodes(root->right, str + "1");
}

// Build Huffman Tree and print codes by traversing the tree
void buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;

    // Create a priority queue to store live nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Create a leaf node for each character and add it to the priority queue
    for (int i = 0; i < size; ++i)
        minHeap.push(new Node(data[i], freq[i]));

    // Iterate while size of heap doesn't become 1
    while (minHeap.size() != 1) {
        // Extract the two nodes of minimum frequency from the heap
        left = minHeap.top();
        minHeap.pop();

        right = minHeap.top();
        minHeap.pop();

        // Create a new internal node with a frequency equal to the sum of the two nodes' frequencies.
        // Make the two extracted nodes as children of this new node.
        // Add this node to the heap with a special character '$' to indicate an internal node.
        top = new Node('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        minHeap.push(top);
    }

    // Print the Huffman codes using the Huffman tree built
    printCodes(minHeap.top(), "");
}

// Main function
int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int size = sizeof(arr) / sizeof(arr[0]);

    buildHuffmanTree(arr, freq, size);

    return 0;
}
