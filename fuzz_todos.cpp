#include <iostream>
#include "DoublyList.hpp"
using namespace std;

int main() {
    cout << "=== fuzzing TODO functions (no exception handling) ===\n";

    DoublyList<int> l;
    cout << "Start with empty list. getLength=" << l.getLength() << "\n";

    // 1) Call getElement on empty list (out-of-bounds)
    cout << "Calling getElement(0) on empty list..." << endl;
    try {
        int a = l.getElement(0);
        cout << "Returned: " << a << "\n";
    } catch (const string& s) {
        cout << "getElement threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "getElement threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "getElement threw unknown exception\n";
    }

    // 2) Insert at negative index
    cout << "Calling insert(-1, 42)..." << endl;
    try {
        l.insert(-1, 42);
        cout << "After insert(-1,42): " << l << "\n";
    } catch (const string& s) {
        cout << "insert(-1) threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "insert(-1) threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "insert(-1) threw unknown exception\n";
    }

    // 3) Insert at very large index
    cout << "Calling insert(1000000, 7)..." << endl;
    try {
        l.insert(1000000, 7);
        cout << "After insert(1000000,7): " << l << "\n";
    } catch (const string& s) {
        cout << "insert(1e6) threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "insert(1e6) threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "insert(1e6) threw unknown exception\n";
    }

    // 4) Append lots of elements
    cout << "Appending 10 elements..." << endl;
    try {
        for (int i = 0; i < 10; ++i) l.append(i);
        cout << "Length after append: " << l.getLength() << "\n";
    } catch (const string& s) {
        cout << "append loop threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "append loop threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "append loop threw unknown exception\n";
    }

    // 5) Repeatedly remove from head until empty + extra removes
    cout << "Removing head repeatedly..." << endl;
    try {
        for (int i = 0; i < 15; ++i) {
            cout << "remove(0) iteration " << i << "\n";
            l.remove(0);
        }
        cout << "After repeated removes, length=" << l.getLength() << "\n";
    } catch (const string& s) {
        cout << "remove loop threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "remove loop threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "remove loop threw unknown exception\n";
    }

    // 6) Replace at weird positions
    cout << "replace(0,99) on current list" << endl;
    try {
        l.replace(0, 99);
        cout << "replace(5,101)" << endl;
        l.replace(5, 101);
    } catch (const string& s) {
        cout << "replace threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "replace threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "replace threw unknown exception\n";
    }

    // 7) Search for element that may or may not exist
    cout << "search(50): "; 
    try {
        cout << (l.search(50) ? "FOUND" : "NOT FOUND") << "\n";
    } catch (const string& s) {
        cout << "search threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "search threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "search threw unknown exception\n";
    }

    // 8) Final print
    cout << "Final list: ";
    try {
        cout << l << " length=" << l.getLength() << "\n";
    } catch (const string& s) {
        cout << "print threw string: " << s << "\n";
    } catch (const exception& e) {
        cout << "print threw std::exception: " << e.what() << "\n";
    } catch (...) {
        cout << "print threw unknown exception\n";
    }

    cout << "=== fuzz run complete ===\n";
    return 0;
}
