


class Book:

    def __init__(self, title, author, num_pages):
        self.title = title
        self.author = author
        self.num_pages = num_pages
    

    def __str__(self):
        return f"{self.title} by {self.author}"
    
    def __eq__(self, other):
        return self.title == other.title and self.author == other.author
    
    def __lt__(self, other): #lt = less than
        return self.num_pages < other.num_pages
    
    def __gt__(self, other): #lt = greater than
        return self.num_pages > other.num_pages
    
    def __add__(self, other):
        return self.num_pages + other.num_pages
    
    def __contains__(self, keyword):
        return keyword in self.title or keyword in self.author
    
    def __getitem__(self, key):
        if "title" == key:
            return self.title
        elif "author" == key:
            return self.author
        elif "number of pages" == key:
            return self.num_pages
        else:
            return f"Key '{key}' was not found"





