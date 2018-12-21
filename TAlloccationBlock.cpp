#include "TAlloccationBlock.h"
#include <iostream>

TAlloccationBlock::TAlloccationBlock(size_t size, size_t count): _size(size), _count(count){
    _used_blocks = (char*) malloc(_size*_count);
    _free_blocks = (void **) malloc(sizeof(void*)  * _count);

    for (size_t i =0; i<_count; i++) _free_blocks[i] = _used_blocks + i*_size;
    _free_count = _count;
    std::cout << "TAlloccation: memory init" << std::endl;
}

void *TAlloccationBlock::allocate(){
    void *result = nullptr;

    if(_free_count > 0){
        result = _free_blocks[_free_count-1];
        _free_count--;
        std::cout << "TAlloccationBlock: allocate" << (_count - _free_count) << "of" << _count << std::endl;
    } else {
        std::cout << "TAlloccationBlock: no memory exception " << std::endl;
    }
    return result;
}

void TAlloccationBlock::deallocate(void *pointer){
    std::cout << "TAlloccationBlock: deallocate block" << std::endl;
    _free_blocks[_free_count] = pointer;
    _free_count ++;
}

bool TAlloccationBlock::has_free_blocks(){
    return _free_count > 0;
}

TAlloccationBlock::~TAlloccationBlock(){
    if (_free_count < _count){
        std::cout << "TAlloccationBlock: memory leak" << std::endl;
    } else {
        std::cout << "TAlloccationBlock: memory freed" << std::endl;
    }
    delete _free_blocks;
    delete _used_blocks;
}