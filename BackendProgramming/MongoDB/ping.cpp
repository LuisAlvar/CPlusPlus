// ping.cpp
#include <cstdlib>
#include <string>

#include <bsoncxx/json.hpp>
#include <mongocxx/client.hpp>
#include <mongocxx/instance.hpp>

using namespace std;

string lookup_env(const string &name) {
  char *env = getenv(name.c_str());
  if(!env){
    throw runtime_error("missing environment variable: " + name);
  }
  return env; 
}


int main() {

  try
  {
    // Create an instance 
    mongocxx::instance inst{};

    string connection_string = lookup_env("MONGO_CONNECTION_STRING");

    const auto uri = mongocxx::uri{connection_string};

    // Set the version of the Stable API on the client 
    mongocxx::options::client client_options;
    const auto api = mongocxx::options::server_api {
      mongocxx::options::server_api::version::k_version_1
    };
    client_options.server_api_opts(api);

    // Setup the connectiona and get a handle on the "admin" database.
    mongocxx::client conn {uri, client_options};
    mongocxx::database db = conn["admin"];

    // Ping the database
    const auto ping_cmd = bsoncxx::builder::basic::make_document(
      bsoncxx::builder::basic::kvp("ping", 1)
    );
    db.run_command(ping_cmd.view());

    cout 
      << "Pinged your deployment using the MongoDB C++ Driver." 
      << "You successfully connected to MongoDB!"
      << endl;

  }
  catch(const std::exception& e)
  {
    cerr << "Exceptions: " << e.what() << '\n';
  }
  
  return 0;
}