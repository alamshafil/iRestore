#ifndef PWN_HPP_
#define PWN_HPP_

#include "Usb.hpp"

namespace Pwn {
  int Device(uint16_t Vid, uint16_t Pid)
  {
  	  uint16_t vendorID = 0x5AC;
  		uint16_t productID = 0x1227;
  		int ret = 0;
  		libusb_handler_t *dev = NULL;

  		std::cout << "[i] Please connect a device in DFU Mode..." << '\n';
  		dev = acquire_device(vendorID, productID);
  		if (dev == NULL) {
  			return -1;
  		}
  		sleep(2);
  		std::cout << "Device Found: " << dev->serialnumber << '\n';

  		dev = reconnect_device(dev, vendorID, productID, 1);
  //
  		auto A10 = strstr((char*)dev->serialnumber, "8010");
  		auto A9 = strstr((char*)dev->serialnumber, "8000");
  		auto a9 = strstr((char*)dev->serialnumber, "8003");
  		auto A8 = strstr((char*)dev->serialnumber, "7000");
  		auto A7 = strstr((char*)dev->serialnumber, "8960");
  		auto A6 = strstr((char*)dev->serialnumber, "8950");
  		auto A4 = strstr((char*)dev->serialnumber, "8930");
  		auto idk1 = strstr((char*)dev->serialnumber, "8922");
  		auto idk2 = strstr((char*)dev->serialnumber, "8920");
  //  all of these^ will use ipwnder_lite

  //
    	auto A11 = strstr((char*)dev->serialnumber, "8015");
  // for t8015
  chdir("Resources");
  system("sudo chmod +x ipwnder_macosx && sudo chmod +x ipwndfuA11");

  if(A10 != NULL)
  {
  	Info("Found A10 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(A9 != NULL)
  {
  	Info("Found A9 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(a9 != NULL)
  {
  	Info("Found A9 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(A8 != NULL)
  {
  	Info("Found A8 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(A7 != NULL)
  {
  	Info("Found A7 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(A6 != NULL)
  {
  	Info("Found A6 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(A4 != NULL)
  {
  	Info("Found A4 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(idk1 != NULL)
  {
  	Info("Found 8922 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(idk2 != NULL)
  {
  	Info("Found 8920 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwnder_macosx -p");
  	return 0;
  }
  else if(A11 != NULL)
  {
  	Info("Found A11 Device. Putting device in pwned DFU Mode and removing signature checks...\n");
  	system("./ipwndfuA11 -p && ./ipwndfuA11 --patch");
  	return 0;
  }
  Info("The device should now be in pwned DFU Mode with signature checks removed.");
  return 0;
  }
};

#endif /* PWN_HPP_ */
