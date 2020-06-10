
#include "kmc_api/kmc_file.h"

#include <iostream>


void print_execution_options()
{
    // std::cout << "KMC dump ver. " << KMC_VER << " (" << KMC_DATE << ")\n";
    
    std::cout << "Usage:\n";
    std::cout << "kmc_dump [options] <kmc_database> <output_file>\n";
    
    std::cout << "Parameters:\n";
    std::cout << "<kmc_database> - kmer_counter's output\n";

    std::cout << "Options:\n";
    std::cout << "-ci<value> - do not print k-mers occuring less than <value> times\n";
    std::cout << "-cx<value> - do not print k-mers occuring more than <value> times\n";
}


void parse_input(int argc, char** argv, uint32_t& min_count_to_set, uint32_t& max_count_to_set, std::string& input_file_name, std::string& output_file_name)
{
    if(argc < 3)
    {
        print_execution_options();
        exit(EXIT_FAILURE);
    }


    int i;
    for(i = 1; i < argc; ++i)
        if(argv[i][0] == '-')
        {
            if(strncmp(argv[i], "-ci", 3) == 0)
                min_count_to_set = atoi(&argv[i][3]);
            else if(strncmp(argv[i], "-cx", 3) == 0)
                max_count_to_set = atoi(&argv[i][3]);
        }
        else break;

    
    if(argc - i < 2)
    {
        print_execution_options();
        exit(EXIT_FAILURE);
    }


    input_file_name = std::string(argv[i]);
    output_file_name = std::string(argv[i + 1]);
}


void process_kmer_database(const uint32_t min_count_to_set, const uint32_t max_count_to_set, const std::string& input_file_name, const std::string& output_file_name)
{
    FILE* out_file = fopen(output_file_name.c_str(), "wb");

    if(out_file == NULL)
    {
        print_execution_options();
        exit(EXIT_FAILURE);
    }

    setvbuf(out_file, NULL, _IOFBF, 1 << 24);


    CKMCFile kmer_database;
    if(!kmer_database.OpenForListing(input_file_name))
    {
        std::cerr << "Error opening the k-mer database. Aborting.\n";
        exit(EXIT_FAILURE);
    }


    CKMCFileInfo database_info;
    kmer_database.Info(database_info);

    CKmerAPI kmer_object(database_info.kmer_length);
    if(min_count_to_set && !kmer_database.SetMinCount(min_count_to_set))
        exit(EXIT_FAILURE);

    if(max_count_to_set && !kmer_database.SetMaxCount(max_count_to_set))
        exit(EXIT_FAILURE);


    std::string str;
    uint32_t counter;
    while(kmer_database.ReadNextKmer(kmer_object, counter))
    {
        kmer_object.to_string(str);
        // std::cout << str << "\t" << counter << "\n";
        fprintf(out_file, "%s\t%u\n", str.c_str(), counter);
    }


    fclose(out_file);
    kmer_database.Close();
}


int main(int argc, char** argv)
{
    uint32_t min_count_to_set = 0;
    uint32_t max_count_to_set = 0;
    std::string input_file_name;
    std::string output_file_name;


    parse_input(argc, argv, min_count_to_set, max_count_to_set, input_file_name, output_file_name);

    process_kmer_database(min_count_to_set, max_count_to_set, input_file_name, output_file_name);


    return EXIT_SUCCESS;
}