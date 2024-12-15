#include <iostream>

template <typename T>
class Box {
private:
    T value;

public:
    Box(T v) : value(v) {}

    void setValue(T v) {
        value = v;
    }

    T getValue() const {
        return value;
    }
};

int main() {
    Box<int> intBox(123);
    std::cout << "intBox contains: " << intBox.getValue() << std::endl;

    Box<double> doubleBox(456.789);
    std::cout << "doubleBox contains: " << doubleBox.getValue() << std::endl;

    Box<std::string> stringBox("Hello, Templates!");
    std::cout << "stringBox contains: " << stringBox.getValue() << std::endl;

    return 0;
}
