
from book import Book

def main():
    book1 = Book("The Hobbit", "J.R.R Tolkien", 310)
    book2 = Book("Harry Potter", "J.K ROWLING", 223)
    book3 = Book("The Lion, the Witch and the Wardrobe", "C.S. Lewis", 172)
    book4 = Book("The Hobbit", "J.R.R Tolkien", 325)

    print(book1)
    print(book2)
    print(book3)

    print(book1 == book4)
    print(book1 == book2)
    print(book1 == book3)
    print()

    print(book1 < book4)
    print(book1 < book2)
    print(book1 < book3)
    print()

    print(book1 > book4)
    print(book1 > book2)
    print(book1 > book3)
    print()

    print(book1 + book4)
    print(book1 + book2)
    print(book1 + book3)
    print()

    print("Lion" in book3)
    print("Harry" in book3)
    print("Harry" in book2)
    print("Tolkien" in book1)
    print()

    print(book1["title"])
    print(book1["author"])
    print(book1["number of pages"])
    print(book1["audio"])





if __name__ == "__main__":
    main()