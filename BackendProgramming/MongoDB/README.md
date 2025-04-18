## 

```bash
docker pull mongodb/mongodb-community-server:latest
```

```bash
docker run --name mongodb -p 27017:27017 -d mongodb/mongodb-community-server:latest
```

This allos you to connect to MongoDB with a localhost:27017 connection string


```bash
docker pull mongodb/mongo-cxx-driver
```

## Docker Image Creation And 
Make sure that both Dockerfile and ping.cpp are in the same director as each other. 

Now we need to build the Docker image. Let's name this image mongocxx-ping
```bash 
docker build . -t mongocxx-ping
```

We need to set the environment vairable that contains the connections string for our database. 

```bash
mongodb://localhost:27017 - if its on the host, just use the localhost address
```

```bash
mongodb://mongodb:27017 - if the code is running inside the container, it would be best to rewirte it to us elinks and referring to the mongo container by name 
```

Now that we have constructed the connection string, run the command below with said connection string. 

```bash
docker run --env MONGO_CONNECTION_STRING='mongodb://localhost' --rm mongocxx-ping
```