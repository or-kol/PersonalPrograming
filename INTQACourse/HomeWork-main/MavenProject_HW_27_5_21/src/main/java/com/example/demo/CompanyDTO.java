package com.example.demo;

public class CompanyDTO {
    public String name;
    public String catchphrase;
    public String bs;

    public CompanyDTO() {

    }

    public CompanyDTO(String name, String catchphrase, String bs) {
        this.name = name;
        this.catchphrase = catchphrase;
        this.bs = bs;
    }

    @Override
    public String toString() {
        return "CompanyDTO{" +
                "name='" + name + '\'' +
                ", catchphrase='" + catchphrase + '\'' +
                ", bs='" + bs + '\'' +
                '}';
    }
}
