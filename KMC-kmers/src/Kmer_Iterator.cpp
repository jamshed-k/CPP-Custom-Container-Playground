
#include "Kmer_Iterator.hpp"
#include "Kmer_Container.hpp"


Kmer_Iterator::Kmer_Iterator(Kmer_Container* const kmer_container, const bool at_begin):
    kmer_container(kmer_container)
{
    CKMCFileInfo info;
    kmer_container->kmc_database.Info(info);

    if(at_begin)
    {
        kmer_object = CKmerAPI(info.kmer_length);
        advance();
    }
}


void Kmer_Iterator::advance()
{
    uint32_t dummy;
    if(!kmer_container->kmc_database.ReadNextKmer(kmer_object, dummy))
        kmer_object = CKmerAPI();
}


Kmer_Iterator::Kmer_Iterator(const Kmer_Iterator& rhs):
    kmer_container(rhs.kmer_container), kmer_object(rhs.kmer_object)
{}


Kmer_Iterator::const_ref Kmer_Iterator::operator*() const
{
    return kmer_object;
}


Kmer_Iterator::const_ptr Kmer_Iterator::operator->() const
{
    return &kmer_object;
}


const Kmer_Iterator& Kmer_Iterator::operator++()
{
    advance();

    return *this;
}


Kmer_Iterator Kmer_Iterator::operator++(int)
{
    Kmer_Iterator clone(*this);
    advance();

    return clone;
}


const Kmer_Iterator& Kmer_Iterator::operator=(const Kmer_Iterator& rhs)
{
    kmer_container = rhs.kmer_container;
    kmer_object = rhs.kmer_object;

    return *this;
}


bool Kmer_Iterator::operator==(const Kmer_Iterator& rhs) const
{
    return kmer_container == rhs.kmer_container && kmer_object == rhs.kmer_object;
}


bool Kmer_Iterator::operator!=(const Kmer_Iterator& rhs) const
{
    return !(this->operator==(rhs));
}
