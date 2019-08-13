module Usp = {
  type t = {
    title: string,
    text: string,
  };

  let make = ((title, text)) => {title, text};
};

module MiniUsp = {
  type t = {
    illustration: string,
    title: string,
    text: string,
  };

  let make = ((title, text, illustration)) => {title, text, illustration};
};

type t = {
  title: string,
  illustration: string,
  lead: string,
  usps: list(Usp.t),
};

let make = offer => {
  title: offer##offerTitle,
  lead: offer##offerLead##offerLead,
  illustration: offer##offerIllustrationImage##file##url,
  usps: [
    Usp.make((
      offer##offerUspOneTitle,
      offer##offerOneUspText##offerOneUspText,
    )),
    Usp.make((
      offer##offerUspTwoTitle,
      offer##offerTwoUspText##offerTwoUspText,
    )),
    Usp.make((
      offer##offerUspThreeTitle,
      offer##offerThreeUspText##offerThreeUspText,
    )),
    Usp.make((
      offer##offerUspFourTitle,
      offer##offerFourUspText##offerFourUspText,
    )),
  ],
};
