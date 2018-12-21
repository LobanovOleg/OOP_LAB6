#ifndef TALLOCCATIONBLOCK_H
#define TALLOCCATIONBLOCK_H
#include <cstdlib>

class TAlloccationBlock {
public:
    TAlloccationBlock(size_t size, size_t count); //конструктор блока
    void *allocate(); // Аллоцирование под запрос
    void deallocate(void *pointer); // Возврат памяти
    bool has_free_blocks(); // Наличие свободных блоков
    virtual ~TAlloccationBlock(); // Деконструктор блока
private:
    size_t _size; //сколько выделено
    size_t _count;// текущий размер
    char * _used_blocks; // используемые блоки
    void ** _free_blocks;// свободные блоки
    size_t _free_count;// число свободных
};
#endif