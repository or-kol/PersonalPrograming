package com.example.demo;

public class UserDTO {
    public Integer id;
    public String name;
    public String username;
    public String email;
    public CompanyDTO company;

    public UserDTO() {

    }

    public UserDTO(Integer id, String name, String username, String email, CompanyDTO company) {
        this.id = id;
        this.name = name;
        this.username = username;
        this.email = email;
        this.company = company;
    }

    @Override
    public String toString() {
        return "UserDTO{" +
                "id=" + id +
                ", name='" + name + '\'' +
                ", username='" + username + '\'' +
                ", email='" + email + '\'' +
                ", company=" + company +
                '}';
    }
}

