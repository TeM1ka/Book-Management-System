#pragma once 
#include "Library.h" 
#include <vector> 
#include <string> 
#include "Book.h" 
#include "../include/json.hpp" 
#include <fstream>


std::vector<Book> load_users(const std::string& filename)
{
    std::ifstream file(filename);
    std::vector<Book> books;
    if (file.is_open()) 
    {
        json j;
        file >> j;
        file.close();
        books = j.get<std::vector<Book>>();
    }
    else 
    {
        std::cerr << "Could not open file for reading." << std::endl;
    }
    return books;
}

Library::Library(std::vector<Book> library)
    : library(std::move(library))
{}

void Library::addBook(const Book& book)
{
    for (const auto& elem : library)
        if (check(elem, book))
            return;

    library.push_back(book);
}

void Library::removeBook(const Book& book)
{
    std::size_t index = library.size();
    for (std::size_t i = 0; i < library.size(); ++i)
    {
        if (check(library[i], book))
        {
            index = i;
            break;
        }
    }
    if (index == library.size())
        return;
    library.erase(library.begin() + index, library.begin() + index + 1);
}

void Library::showBook() const
{
    for (const auto& elem : library)
        elem.printBook();
}

std::vector<Book> Library::getBooks() const
{
    return library;
}