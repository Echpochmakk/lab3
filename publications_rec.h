#ifndef STRUCT_RECORD_H
#define STRUCT_RECORD_H

typedef struct {
    char title[100];
    char author_last_name[50];
    char author_initials[20];
    char journal_title[50];
    int publication_year;
    int journal_volume;
    int is_in_rinc; 
    int page_count;
    int citation_count;
} PublicationRecords;

#endif 
