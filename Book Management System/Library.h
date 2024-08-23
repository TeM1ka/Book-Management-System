#pragma once 
#include <vector> 
#include <string> 
#include "Book.h" 
#include "../include/json.hpp" 
#include <iostream>

using json = nlohmann::json;

class Library
{
private:
    std::vector<Book> library;

    bool equalAuthors(const std::vector<Author>& rhs, const std::vector<Author>& lhs)
    {
        if (rhs.size() and rhs.size() != lhs.size())
            return false;

        for (int i = 0; i < rhs.size(); ++i)
            if (rhs[i].getName() != lhs[i].getName())
                return false;
        return true;
    }


    bool equalGenre(const std::vector<Genre>& rhs, const std::vector<Genre>& lhs)
    {
        if (rhs.size() and rhs.size() != lhs.size())
            return false;

        for (int i = 0; i < rhs.size(); ++i)
            if (rhs[i].getGenre() != lhs[i].getGenre())
                return false;
        return true;
    }

    bool check(const Book& rhs, const Book& lhs)
    {
        if (rhs.getTitle() == lhs.getTitle() && equalGenre(rhs.getGener(), lhs.getGener()) &&
            equalAuthors(rhs.getAuthors(), lhs.getAuthors()) && rhs.getYear() == lhs.getYear())
            return true;
    }

public:
    Library(std::vector<Book> library);

    Library() = default;

    void addBook(const Book& book);

    void removeBook(const Book& book);

    void showBook() const;

    std::vector<Book> getBooks() const;

};