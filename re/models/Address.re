type t = {
  address: string,
  city: string,
  phoneNumber: string,
  email: string,
  zip: string,
  orgNumber: string,
  title: string,
};

let make = address => {
  address: address##address1,
  city: address##city,
  phoneNumber: Telefonnummer.parse(address##contactPhone),
  email: address##contactMail,
  zip: address##zip,
  orgNumber: address##orgNumber,
  title: address##title,
};
