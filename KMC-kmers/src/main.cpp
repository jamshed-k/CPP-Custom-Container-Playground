
#include "Kmer_Container.hpp"


void print_database_info(CKMCFileInfo& info)
{
    std::cout << "k-mer database information:\n";
    std::cout << "k-Mer length: " << info.kmer_length << "\n";
    std::cout << "Min and max k-mer count: [" << info.min_count << ", " << info.max_count << "]\n";
    std::cout << "Total number of k-mers: " << info.total_kmers << "\n";
}


int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Usage: <program> <kmc_database>\n";
        std::exit(EXIT_FAILURE);
    }

    const std::string kmc_file(argv[1]);

    // Open the k-mers container.
    Kmer_Container kmers(kmc_file);


    // Get some information about the underlying KMC database.
    CKMCFileInfo info = kmers.info();
    print_database_info(info);    


    // Iterating over the k-mers on the database from disk.

    std::cout << "\nSet of unique k-mers:\n";
    auto it_beg = kmers.begin();
    auto it_end = kmers.end();
    for(auto it = it_beg; it != it_end; ++it)
        // Use the iterator from here
        std::cout << it->to_string() << "\n"; // [Or,] std::cout << (*it).to_string() << "\n";


    // Close the container.
    kmers.close();


    return 0;
}
