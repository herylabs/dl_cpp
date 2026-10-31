#include <vector>

namespace nn
{
    class Tensor{
    private:
        std::vector<float> _data;
        std::vector<std::size_t> _shape;
        std::vector<std::size_t> _stride;

    public:
        Tensor(float data);
        Tensor(std::vector<float> data);
        Tensor(std::vector<std::vector<float>> data);

        // Méthod item
        const float &item() const;
        float & item();

        // Operators
        const float & operator()(std::size_t i) const;
        float & operator()(std::size_t i);
        
        const float & operator()(std::size_t i, std::size_t j) const;
        float & operator()(std::size_t i, std::size_t j);
    };
} // namespace nn