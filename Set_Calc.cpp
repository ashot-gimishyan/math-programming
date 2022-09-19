// Set Theory

#include <iostream>
#include <vector>

template <class S>
class Set {
 private:
  std::vector<S> elements;

 public:
  Set(std::vector<S>& vector_) {
    elements = vector_;
    make_unique(elements);
  };

  void make_unique(std::vector<S>& vector_) {
    std::vector<S> tmp;
    bool flag = false;
    for (size_t i = 0; i < vector_.size(); i++) {
      for (size_t j = 0; j < tmp.size(); j++) {
        if (vector_[i] == tmp[j]) {
          flag = true;
          break;
        }
      }

      if (!flag) {
        tmp.push_back(elements[i]);
      }
      flag = false;
    }

    elements.clear();
    elements.insert(elements.begin(), tmp.begin(), tmp.end());
  }

  friend std::ostream& operator<<(std::ostream& out, const Set<S>& s) {
    for (size_t i = 0; i < s.elements.size(); i++) {
      std::cout << s.elements[i] << ' ';
    }
    std::cout << std::endl;
    return out;
  }

 protected:
};

int main(int argc, char const* argv[]) {
  std::vector<char> v = {'a','a', 'b', 'b', 'b'};
  Set my_set(v);
  std::cout << my_set;

  return 0;
}
