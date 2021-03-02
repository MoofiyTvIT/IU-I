//
// Created by Muwaffaq Imam on 07.02.2021.
//
#include <iostream>
#include <vector>

void question2();

void question3();

void question4();

void question5();

using namespace std;


//int main() {
//
//    return 0;
//}

/******************************************************* Question2 *************************************************************************/

// Only read arguments, so it safe to pass them by const-reference
void print(const string &label, const vector<double> &data) {
    cout << label << ": { ";
    for (double d : data)
        cout << d << ' ';
    cout << "}\n";
}

double maxv(const vector<double> &v) {
    double max = v[0];   // We could not make assumptions about vector values
    // and so we must initalize the max track to an element
    for (double d : v)
        if (d > max) max = d;

    return max;
}

/**
 * Write a function which will returns the largest element of a vector.
 */
void question2() {
    vector<double> test_data{-5, 0, 6.7, -1000, 10.1e5, 10e5};
    print("Test data", test_data);
    cout << "Largest element from data: " << maxv(test_data) << '\n';
}

/******************************************************* Question3 *************************************************************************/

// Only read arguments, so it safe to pass them by const-reference
void print(const string &label, const vector<int> &data) {
    cout << label << ": { ";
    for (int i : data)
        cout << i << ' ';
    cout << "}\n";
}

// Only read arguments, so it safe to pass them by const-reference
void print(const string &label, const vector<string> &data) {
    cout << label << ": { ";
    for (string i : data)
        cout << "\"" << i << "\" ";
    cout << "}\n";
}

// Generates a vector<int> with the lengths of strings on v.
vector<int> gen_length_vector(const vector<string> &v) {
    vector<int> lv;

    for (const string &s : v)
        lv.push_back(s.size());

    return lv;
}

// Returns the longest string(s). It returns a vector since v could contain
// various strings with the same size.
// Precondition:
//  v size must be at least 1. This is, v could not be empty.
vector<string> longest_string(const vector<string> &v) {
    size_t max{v[0].size()};    // Init max tracking to size of the first element

    // First vector traversal to find longest length
    for (string s : v)
        if (s.size() > max) max = s.size();

    // Second vector traversal to get longest strings
    vector<string> lv;
    for (string s: v)
        if (s.size() == max) lv.push_back(s);

    return lv;
}


// Returns the shortest string(s). It returns a vector since v could contain
// various strings with the same size.
// Precondition:
//  v size must be at least 1. This is, v could not be empty.
vector<string> shortest_string(const vector<string> &v) {

    size_t min{v[1].size()};    // Init min tracking to size of the first element

    // First vector traversal to find shortest length
    for (string s : v)
        if (s.size() < min) min = s.size();

    // Second vector traversal to get shortest strings
    vector<string> sv;
    for (string s: v)
        if (s.size() == min) sv.push_back(s);

    return sv;
}

// Returns the first lexicograpically string from v.
// We don't want to modify the argument, so we have two options:
//  - Pass by const-reference and make a copy inside
//  - Pass by value
// In each case we declare our intention to not modify the argument.
// Precondition:
//  v size must be at least 1. This is, v could not be empty.
string first_string(const vector<string> &v) {
    vector<string> tmp{v};
    sort(tmp.begin(), tmp.end());
    return tmp[0];
}


// Returns the last lexicograpically string from v.
// We don't want to modify the argument, so we have two options:
//  - Pass by const-reference and make a copy inside
//  - Pass by value
// In each case we declare our intention to not modify the argument.
// Precondition:
//  v size must be at least 1. This is, v could not be empty.
string last_string(vector<string> v) {

    string last{v[0]};
    for (string s : v)
        // bigger means less in alphabetical order  Bill > Ali
        if (s > last) last = s;
    return last;
}

/**
 * Write a function which takes a vector<string> argument and returns a vector<int> which contains the number of char in each string.
 * Find the the longest and and the shortest string and the lexicographically (alphabetical) first and last string.
 */
void question3() {
    vector<string> data{"one", "two", "three", "four", "five", "six", "seven"};
    print("The strings vector is", data);
    print("The corresponding lengths are", gen_length_vector(data));
    print("The longest strings are", longest_string(data));
    print("The shortest strings are", shortest_string(data));
    cout << "The first lexicographically string is: \""
         << first_string(data) << "\"\n";
    cout << "The last lexicographically string is: \""
         << last_string(data) << "\"\n";
}


/******************************************************* Question 4 *************************************************************************/

struct Stats {
    double max{0};
    double min{0};
    double mean{0};
    double median{0};
};


void print_stats(const Stats &stats) {
    cout << "Statistics:\n\tMax: " << stats.max << '\n'
         << "\tMin: " << stats.min << '\n'
         << "\tMean: " << stats.mean << '\n'
         << "\tMedian: " << stats.median << '\n';
}

// Calculates the the mean of the set of values in v
double mean(const vector<double> &v) {
    double sum{0};
    for (double d : v)
        sum += d;
    return sum / v.size();
}

// Calculates the the median of the set of values in v
// The vector iss supposed to be sorted!
// When the number of elements is even, the median is defined
// as the mean between the two most central values in the series.
double median(const vector<double> &v) {
    if ((v.size() % 2) == 1)          // odd number of elements
        return v[v.size() / 2];// the central element

    // if even sum the 2 central elements
    size_t centerElement{v.size() / 2};
    return (v[centerElement - 1] + v[centerElement]) / 2;
}

Stats get_stats(const vector<double> &v)
// Doesn't modify the passed vector
{
    vector<double> tmp{v};  // temporal vector to work

    sort(tmp.begin(), tmp.end());   // sort the work vector
    Stats stats;
    stats.min = tmp[0];
    stats.max = tmp[tmp.size() - 1];
    stats.mean = mean(tmp);
    stats.median = median(tmp);
    print("Sorted data", tmp);
    return stats;
}

/**
 * Write a function that finds the smallest and the largest element of a vector argument and also computes the mean and the median.
 *  Which of the two ways of returning several result values do you prefer and why?
 *  Conditions:
*   Do not use global variables.
*Use a struct containing the results.

 */
void question4() {
    // Mean: 5.28571, Median: 6;
    vector<double> odd_data{3, 9, 1, 8, 7, 6, 3};
    // Mean: 4.75, Median: 4.5
    vector<double> even_data{4, 1, 9, 8, 5, 3, 2, 6};

    print("Odd (number of elements) data", odd_data);
    print_stats(get_stats(odd_data));
    cout << '\n';

    print("Even (number of elements) data", even_data);
    print_stats(get_stats(even_data));
    cout << '\n';
}

/******************************************************* Question5 *************************************************************************/




constexpr size_t name_no{5};    // Number of name to ask for

// Checks if string s is already present on vector v.
bool is_in(const vector<string> &v, const string &s) {
    for (string x : v)
        if (x == s) return true;
    return false;
}

// Asks the user for name_no names and adds them to a vector.
// No duplicate names are permitted.
void get_names(vector<string> &name) {
    cout << "Write " << name_no << " people names ...\n";
    for (size_t i = 0; i < name_no; ++i) {
        cout << ": ";
        string n;
        cin >> n;
        while (is_in(name, n)) {
            cout << "Duplicated name " << n << "! Try again ...\n: ";
            cin >> n;
        }
        name.push_back(n);
    }
}

// Get ages for people in name vector. Adds them to a "parallel" vector
// correlated by indexes.
void get_ages(const vector<string> &name, vector<double> &age) {
    cout << "Give me the ages of each person, please ...\n";
    for (string n : name) {
        cout << "How old is " << n << "? ";
        double a{0};
        while (!(cin >> a)) {
            // Make sure that we read a number.
            cout << "Sorry, I don't understand you! How old is " << n << "? ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        age.push_back(a);
    }
}

// Prints a line with a name and its respective age, from the same both
// elements of two distinct vectors.
void print_pairs(const vector<string> &name, const vector<double> &age) {
    size_t limit = name.size();     // To avoid evaluate a function call
    // at the for condition each loop
    for (size_t i = 0; i < limit; ++i)
        cout << '\t' << name[i] << " is " << age[i] << " years old.\n";
}

// Returns the index at which a name (n) is located on a vector (name).
// As the program goes we are almost sure the name will be present, so an error
// is thrown otherwise.
size_t name_idx(const vector<string> &name, const string &n) {
    size_t limit = name.size();
    for (size_t i = 0; i < limit; ++i)
        if (name[i] == n) return i;

    return -1;
}

// Sort a vector (name) and extends the position changes to a second
// vector (age) of the same size.
void sort_pairs(vector<string> &name, vector<double> &age) {
    vector<string> orig_name{name};   // Reference pre-sorted vector
    vector<double> orig_age{age};     // Source to build a new shuffled vector

    sort(name.begin(), name.end());
    size_t limit = name.size();
    for (size_t i = 0; i < limit; ++i)
        age[i] = orig_age[name_idx(orig_name, name[i])];
}


/**
 * Read five names into a vector<string> name, then prompt the user for the ages of the people named and store the ages in a vector<double> age.
 * Then print out the five (name[i],age[i]) pairs. Sort the names (sort(name.begin(),name.end())) and print out the (name[i],age[i]) pairs.
 *
 * Note: The tricky part here is to get the age vector in the correct order to match the sorted name vector.
 * Hint: Before sorting name, take a copy and use that to make a copy of age in the right order after sorting name.
 */
void question5() {
    vector<string> name;
    vector<double> age;

    get_names(name);
    get_ages(name, age);
    cout << "\nOK! So you tell me about these people:\n";
    print_pairs(name, age);
    sort_pairs(name, age);
    cout << "\nThat sorted by name are:\n";
    print_pairs(name, age);
    cout << '\n';
}

