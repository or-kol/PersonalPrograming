package com.example.demo;

import com.sun.jersey.api.client.Client;
import com.sun.jersey.api.client.ClientResponse;
import com.sun.jersey.api.client.WebResource;
import com.sun.jersey.api.client.config.ClientConfig;
import com.sun.jersey.api.client.config.DefaultClientConfig;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import javax.ws.rs.core.MediaType;
import javax.ws.rs.core.UriBuilder;

@SpringBootTest
class DemoApplicationTests {

	@Test
	void contextLoads() {
	}

	@Test
	public void test_test1() {
		int x = 1;
		assert x == 1;
	}

	@Test
	public void test_get() {
//		ClientConfig clientConfig = new DefaultClientConfig();
//
//		Client client = Client.create(clientConfig);
//		WebResource webResource = client.resource(UriBuilder.fromUri("http://localhost:8080/coupon").build());
//		String result =  webResource.path("").path("").accept(String.valueOf(MediaType.APPLICATION_JSON)).get(String.class);
//		System.out.println(result);
	}

	@Test
	public void test_post() {
//		ClientConfig clientConfig = new DefaultClientConfig();
//
//		String coupon = "{ \"id\": 5, \"title\":\"new coupon\" }";
//
//		Client client = Client.create(clientConfig);
//
//		WebResource webResource = client.resource(UriBuilder.fromUri("http://localhost:8080/coupon").build());
//		ClientResponse resp = webResource.accept("application/json").type("application/json").post(ClientResponse.class, coupon);
//
//		System.out.println(resp.getStatus());
//
//		if(resp.getStatus() != 200) {
//			assert false;
//		}

	}

}
