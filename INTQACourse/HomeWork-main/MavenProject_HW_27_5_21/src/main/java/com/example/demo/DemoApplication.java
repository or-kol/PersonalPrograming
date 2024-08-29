package com.example.demo;

import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import com.sun.jersey.api.client.Client;
import com.sun.jersey.api.client.WebResource;
import com.sun.jersey.api.client.config.ClientConfig;
import com.sun.jersey.api.client.config.DefaultClientConfig;


import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.UriBuilder;
import java.util.ArrayList;


public class DemoApplication {

    public static void main(String[] args) {

        ArrayList<UserDTO> fiveUsersList = new ArrayList<>();

        ClientConfig clientConfig = new DefaultClientConfig();

        Client client = Client.create(clientConfig);

        for (int i = 1; i <= 5; i++) {
            WebResource webResource = client.resource(UriBuilder.fromUri(
                    String.format("http://jsonplaceholder.typicode.com/users/%d", i)).build());

            String result = webResource.path("").path("").accept(String.valueOf(MediaType.APPLICATION_JSON)).
                    get(String.class);

            Gson gson = new Gson();

		    JsonObject jo = JsonParser.parseString(result).getAsJsonObject();

		    UserDTO user = gson.fromJson(jo, UserDTO.class);
		    fiveUsersList.add(user);
        }

        for (UserDTO u : fiveUsersList){
            System.out.println(u);
        }

    }

}
