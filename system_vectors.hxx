#include <initializer_list>
#include <vector>

template<typename Vector>
class system_vectors {
  private:
    std::vector<Vector> vectors;

  public:
    system_vectors(void) = default;

    system_vectors(std::initializer_list<Vector> vectors_init) {
      for(const auto& vr: vectors_init) {
        vectors.push_back(vr);
      }
    }

    void add(const Vector& vector_new) {
      vectors.push_back(vector_new);
    }

    system_vectors<Vector> operator+(const Vector& vector_new) {
      auto system_new{*this};
      system_new.add(vector_new);

      return system_new;
    }

    system_vectors<Vector> operator+=(const Vector& vector_new) {
      *this = *this + vector_new;
      return *this;
    }
};
