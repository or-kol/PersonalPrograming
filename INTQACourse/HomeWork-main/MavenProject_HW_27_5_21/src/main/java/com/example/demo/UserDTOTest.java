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
import com.sun.jersey.api.client.config.ClientConfig;
import org.junit.Test;

import static org.junit.Assert.assertEquals;


public class UserDTOTest {

    @Test
    public void testUserName() {
        ClientConfig clientConfig = new DefaultClientConfig();

        Client client = Client.create(clientConfig);

        WebResource webResource = client.resource(UriBuilder.fromUri("http://jsonplaceholder.typicode.com/users/1").build());

        String result = webResource.path("").path("").accept(String.valueOf(MediaType.APPLICATION_JSON)).
                get(String.class);

        Gson gson = new Gson();

        JsonObject jo = JsonParser.parseString(result).getAsJsonObject();

        UserDTO user1 = gson.fromJson(jo, UserDTO.class);
        assertEquals("Leanne Graham", user1.name);
    }
}
