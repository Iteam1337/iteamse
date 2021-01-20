type t = {
  address: string,
  city: string,
  email: string,
  zip: string,
  postalAddress: string,
  orgNumber: string,
  title: string,
};

let make = address => {
  address: address##address1,
  city: address##city,
  email: address##contactMail,
  zip: address##zip,
  postalAddress: address##zip ++ " " ++ address##city,
  orgNumber: address##orgNumber,
  title: address##title,
};
