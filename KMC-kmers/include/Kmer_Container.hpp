
#ifndef KMER_CONTAINER_HPP
#define KMER_CONTAINER_HPP



#include "kmc_api/kmc_file.h"
#include "Kmer_Iterator.hpp"


class Kmer_Container
{
    friend class Kmer_Iterator;

    typedef Kmer_Iterator iterator;

private:
    
    CKMCFile kmc_database;


public:

    Kmer_Container(const std::string& kmc_file_name);

    CKMCFileInfo info();

    Kmer_Iterator begin();

    Kmer_Iterator end();

    void close();
};



#endif
