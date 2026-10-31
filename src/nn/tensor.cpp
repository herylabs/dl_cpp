#include "nn/tensor.h"
#include <stdexcept>

nn::Tensor::Tensor(float data): _data{data}, _shape{}, _stride{}
{

}

nn::Tensor::Tensor(std::vector<float> data): _data{data}, _shape{data.size()}, _stride{1}
{

}

nn::Tensor::Tensor(std::vector<std::vector<float>> data): _shape{data.size(), data[0].size()}, _stride{data[0].size(), 1}
{
    // Check if dimensions match
    std::size_t n_expected_columns = data[0].size();
    for(std::size_t i = 0; i < data.size(); i++){
        if(data[i].size() != n_expected_columns){
            throw std::invalid_argument("Dimensions are inconsistent.");
        }
    }


    // Store in row major format like pytorch and numpy
    for(std::size_t i = 0; i < data.size(); i++){
        for(std::size_t j = 0; j < data[i].size(); j++){
            _data.push_back(data[i][j]);
        }
    }
}

const float &nn::Tensor::item() const
{
    // works only with scalars and 1d tensors (like in pytorch)
    if(_data.size() == 1)
        return _data[0];
    else
        throw std::runtime_error("item() can only be called on tensors with a single element");
}

float &nn::Tensor::item()
{
    // works only with scalars and 1d tensors (like in pytorch)
    if(_data.size() == 1)
        return _data[0];
    else
        throw std::runtime_error("item() can only be called on tensors with a single element");
}

const float &nn::Tensor::operator()(std::size_t i) const
{
    if(_shape.size() == 0)
        throw std::invalid_argument("Can't index into a scalar. Use item() instead.");

    if(i > _shape[0])
        throw std::invalid_argument("Index " + std::to_string(i) + " is out of bounds for array of size " + std::to_string(_shape[0]));

    
}

float &nn::Tensor::operator()(std::size_t i)
{
    // TODO: insérer une instruction return ici
}

const float &nn::Tensor::operator()(std::size_t i, std::size_t j) const
{
    // TODO: insérer une instruction return ici
}

float &nn::Tensor::operator()(std::size_t i, std::size_t j)
{
    // TODO: insérer une instruction return ici
}
