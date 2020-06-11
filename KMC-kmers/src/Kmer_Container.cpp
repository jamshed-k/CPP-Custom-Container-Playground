
#include "Kmer_Container.hpp"


Kmer_Container::Kmer_Container(const std::string& kmc_file_name)
{
    if(!kmc_database.OpenForListing(kmc_file_name))
    {
        std::cerr << "Error opening KMC database " << kmc_file_name << ". Aborting.\n";
        std::exit(EXIT_FAILURE);
    }
}


CKMCFileInfo Kmer_Container::info()
{
    CKMCFileInfo database_info;
    if(!kmc_database.Info(database_info))
    {
        std::cerr << "Error reading from the KMC database. Aborting.\n";
        std::exit(EXIT_FAILURE);
    }


    return database_info;
}


Kmer_Iterator Kmer_Container::begin()
{
    return Kmer_Iterator(this);
}


Kmer_Iterator Kmer_Container::end()
{
    return Kmer_Iterator(this, false);
}


void Kmer_Container::close()
{
    if(!kmc_database.Close())
    {
        std::cerr << "Error closing the KMC database. Aborting.\n";
        std::exit(EXIT_FAILURE);
    }
}
