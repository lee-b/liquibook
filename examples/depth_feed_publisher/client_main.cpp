
#include <boost/bind.hpp>
#include "depth_feed_connection.h"
#include "depth_feed_subscriber.h"

int main(int argc, const char* argv[])
{
  // Create feed subscriber
  liquibook::examples::DepthFeedSubscriber feed("./templates/Depth.xml");

  // Connect to server
  liquibook::examples::DepthFeedConnection connection(argc, argv);
  liquibook::examples::MessageHandler msg_handler =
      boost::bind(&liquibook::examples::DepthFeedSubscriber::handle_message,
                  &feed, _1, _2);
  liquibook::examples::ResetHandler reset_handler =
      boost::bind(&liquibook::examples::DepthFeedSubscriber::handle_reset,
                  &feed);
  connection.set_message_handler(msg_handler);
  connection.set_reset_handler(reset_handler);
  connection.connect();
  connection.run();

  return 0;
}
