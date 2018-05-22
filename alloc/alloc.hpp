/**
 * alloc.hpp
 * 
 * \author Daniel Salib * \date Mon 14 May 01:43:47 2018
 *
 */

#include <cassert>


#ifndef ALLOC_HPP
#define ALLOC_HPP

class Fast {
    using Byte = uint8_t;
    inline static void* _safe_malloc(size_t size) {
        return reinterpret_cast<void*>(new Byte[size]);
    }
    inline static void _safe_free(void* mem) {
        delete[] reinterpret_cast<Byte*>(mem);
    }
    
    
    static void* _all_mem;
    static void* _blocks;


    static void _push_front(void* mem) {
        *reinterpret_cast<void**>(mem) = _blocks;
        _blocks = mem;
    }

    static void* _pop_front() {
        void* temp = _blocks;
        _blocks = reinterpret_cast<void**>(_blocks);
        return temp;
    }
    
    public:

        static  size_t _mem_size;

#ifdef OPTIMIZED
        
        static void* operator new(size_t size) {
            assert(size == sizeof(Fast));

            if (_all_mem == nullptr) {
                _all_mem = _safe_malloc(_mem_size);
                for(void* i = _all_mem; i < reinterpret_cast<Byte*>(_all_mem) + _mem_size;
                    i = reinterpret_cast<void*>(reinterpret_cast<Byte*>(i) + sizeof(Fast)))
                {
                    _push_front(i);
                }
            }
            
            if (_blocks == nullptr) return _safe_malloc(size);
            else {
                void* front = _blocks;
                _pop_front();
                return front;
            }
            // handle the case when the list is empty
            // if(_blocks.size() == 0) {
            //     return _safe_malloc(size);
            // }

            // // return head of list
            // return _blocks.front();
        }

        static void operator delete(void* mem) {
            // handle the case when mem is part of _all_mem
            Byte* bmem = reinterpret_cast<Byte*>(mem);
            if(mem >= _all_mem && bmem < _mem_size + reinterpret_cast<Byte*>(_all_mem)) {
                _push_front(mem);
            } else {
                _safe_free(mem);
            }
            // handle the case when mem is not part of _all_mem


        }
    
#endif
    
};

size_t Fast::_mem_size = sizeof(Fast) * 100000;
void* Fast::_all_mem = nullptr;
void* Fast::_blocks = nullptr;

#endif /* ALLOC_HPP */
