package com.example.demo;

import com.google.gson.Gson;
import com.google.gson.JsonParser;
import com.sun.jersey.api.client.Client;
import com.sun.jersey.api.client.ClientResponse;
import com.sun.jersey.api.client.WebResource;
import com.sun.jersey.api.client.config.ClientConfig;
import com.sun.jersey.api.client.config.DefaultClientConfig;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.UriBuilder;

import static org.junit.jupiter.api.Assertions.assertEquals;

@SpringBootTest
class DemoApplicationTests {

	private static RestaurantsREPO restaurantsREPO = new RestaurantsREPO
			("jdbc:sqlite:D:\\SQLiteDB\\Project_3_6_21\\ProjectRestaurant.db");


	@Test
	void contextLoads() {
	}

	@Test
	public void test_get_restaurant_id_1() {
		ClientConfig clientConfig = new DefaultClientConfig();

		Client client = Client.create(clientConfig);
		WebResource webResource = client.resource(UriBuilder.fromUri("http://localhost:8080/restaurant/1").build());

		String result = webResource.path("").path("").accept(String.valueOf(MediaType.APPLICATION_JSON)).get(String.class);
		System.out.println(result);

		Gson gson = new Gson();
		RestaurantsDTO restaurant_id1 = gson.fromJson(JsonParser.parseString(result).getAsJsonObject(),
				RestaurantsDTO.class);

		RestaurantsPOJO expectedResult_id1 = restaurantsREPO.getById(1);
		System.out.println(expectedResult_id1);

		assertEquals(expectedResult_id1.Id, restaurant_id1.Id);
		assert restaurant_id1.Name.equals(expectedResult_id1.Name) == true;

	}


	@Test
	public void test_post_restaurant() {
		Gson gson = new Gson();

		ClientConfig clientConfig = new DefaultClientConfig();

		Client client = Client.create(clientConfig);
		WebResource webResource =
				client.resource(UriBuilder.fromUri("http://localhost:8080/restaurant").build());

		RestaurantsDTO Restaurant = new RestaurantsDTO(4, "qwe", "rty", "uio", 44.76);

		ClientResponse resp =
				webResource.path("").path("").accept("application/json").type("application/json").post(ClientResponse.class,
						gson.toJson(Restaurant));

		if(resp.getStatus() != 201) {
			assert false;
		}

		webResource = client.resource(UriBuilder.fromUri("http://localhost:8080/restaurant/4").build());
		String result =  webResource.path("").accept(String.valueOf(MediaType.APPLICATION_JSON)).get(String.class);
		System.out.println(result);

		RestaurantsDTO restaurant_id4 = gson.fromJson(JsonParser.parseString(result).getAsJsonObject(), RestaurantsDTO.class);

		RestaurantsPOJO expectedResult_id4 = restaurantsREPO.getById(4);
		System.out.println(expectedResult_id4);

		assert restaurant_id4.Id == expectedResult_id4.Id;
		assert restaurant_id4.Name.equals(expectedResult_id4.Name) == true;
	}

	@Test
	public void test_put_restaurant() {
		Gson gson = new Gson();

		ClientConfig clientConfig = new DefaultClientConfig();

		Client client = Client.create(clientConfig);
		WebResource webResource =  client.resource(UriBuilder.fromUri("http://localhost:8080/restaurant/2").build());

		RestaurantsDTO restaurant = new RestaurantsDTO(2, "!!!", "nop", "???", 33.189);

		ClientResponse resp = webResource.accept("application/json").type("application/json").put(ClientResponse.class,
				gson.toJson(restaurant));

		if(resp.getStatus() != 200) {
			assert false;
		}

		webResource = client.resource(UriBuilder.fromUri("http://localhost:8080/restaurant/2").build());
		String result =  webResource.path("").accept(String.valueOf(MediaType.APPLICATION_JSON)).get(String.class);
		System.out.println(result);

		RestaurantsDTO restaurant_id2 = gson.fromJson(JsonParser.parseString(result).getAsJsonObject(), RestaurantsDTO.class);

		restaurantsREPO.update("UPDATE Restaurants\n" +
				"SET Name = '!!!', FoodType = '???'\n" +
				"WHERE id = 2;");
		RestaurantsPOJO expectedResult_id2 = restaurantsREPO.getById(2);
		System.out.println(expectedResult_id2);

		assert restaurant_id2.Name.equals(expectedResult_id2.Name) == true;
		assert restaurant_id2.FoodType.equals(expectedResult_id2.FoodType) == true;
	}

	@Test
	public void test_delete_restaurant() {
		Gson gson = new Gson();

		ClientConfig clientConfig = new DefaultClientConfig();

		Client client = Client.create(clientConfig);
		WebResource webResource =  client.resource(UriBuilder.fromUri("http://localhost:8080/restaurant/2").build());
		webResource.accept("application/json").type("application/json").delete();

		webResource = client.resource(UriBuilder.fromUri("http://localhost:8080/restaurant/2").build());
		String result =  webResource.path("").accept(String.valueOf(MediaType.APPLICATION_JSON)).get(String.class);
		System.out.println(result);

		restaurantsREPO.update("DELETE FROM Restaurant WHERE ID = 2;");
		RestaurantsPOJO expectedResult_id2 = restaurantsREPO.getById(2);
		System.out.println(expectedResult_id2);

		assert result.equals("") == true;
	}

}