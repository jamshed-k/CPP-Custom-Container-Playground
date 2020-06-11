
#ifndef KMER_ITERATOR_HPP
#define KMER_ITERATOR_HPP



#include "kmc_api/kmc_file.h"


class Kmer_Container;


class Kmer_Iterator
{
    friend class Kmer_Container;

public:

    typedef Kmer_Iterator iterator;

    // iterator traits
    typedef std::input_iterator_tag iterator_category;
    typedef CKmerAPI value_type;
    typedef int difference_type;
    typedef CKmerAPI* pointer;
    typedef CKmerAPI& reference;

    typedef const CKmerAPI& const_ref;
    typedef const CKmerAPI* const_ptr;


private:

    Kmer_Container* kmer_container;
    CKmerAPI kmer_object;


    // Private constructor

    Kmer_Iterator(Kmer_Container* const kmer_container, const bool at_begin = true);


    // Private modifier

    void advance();

    
public:

    // Copy constructor

    Kmer_Iterator(const iterator& rhs);


    // Accessors

    const_ref operator*() const;

    const_ptr operator->() const;


    // Modifiers

    const iterator& operator++();

    iterator operator++(int);

    const iterator& operator=(const iterator& rhs);


    // Comparators

    bool operator==(const iterator& rhs) const;

    bool operator!=(const iterator& rhs) const;
};



#endif
