module Assets = {
  module Image = {
    let make = asset => (asset##description, asset##file##url);
  };
};

module Employee = {
  type t = {
    avatar: option(string),
    email: string,
    name: string,
    location: Location.t,
    short: string,
    title: string,
    phoneNumber: option(string),
  };

  let make = employee => {
    avatar:
      switch (employee##avatar->Js.Nullable.toOption) {
      | None => None
      | Some(avatar) => Some(avatar##fluid##src)
      },
    email: employee##email,
    name: employee##name,
    location: Location.fromString(employee##location),
    short: employee##short,
    title: employee##title,
    phoneNumber:
      switch (employee##phoneNumber->Js.Nullable.toOption) {
      | Some(pn) => Some(Telefonnummer.parse(pn))
      | _ => None
      },
  };

  let fromArray = employees =>
    employees->Belt.Array.map(make)->Belt.List.fromArray;
};

module Header = {
  type t = {
    url: string,
    localFile: option(Js.t({.})),
    text: string,
    textSecond: option(string),
    textBgColor: Theme.Colors.t,
  };

  let make = headerData => {
    url: headerData##headerImage##file##url,
    localFile:
      switch (headerData##headerImage##localFile->Js.Nullable.toOption) {
      | Some(local) => Some(local##childImageSharp##fluid)
      | None => None
      },
    text: headerData##headerText1,
    textSecond: headerData##headerText2 |> Js.Nullable.toOption,
    textBgColor: headerData##headerTextBgColor->Theme.Colors.fromHex,
  };
};

module Start = {
  type t = {
    ctaTitle: string,
    ctaButton: string,
    ctaText: string,
    headerText1: string,
    headerLead: string,
    weAreTitle: string,
    weAreText: string,
    weOfferTitle: string,
    weOfferText: string,
    ourMethodTitle: string,
    ourMethodText: string,
    contacts: list(Employee.t),
  };

  let make = page => {
    ctaTitle: page##ctaTitle,
    ctaText: page##ctaText##ctaText,
    ctaButton: page##ctaButtonText,
    headerText1: page##headerText1,
    headerLead: page##headerLead##headerLead,
    weAreTitle: page##weAreTitle,
    weAreText: page##weAreText##weAreText,
    weOfferTitle: page##weOfferTitle,
    weOfferText: page##weOfferText##weOfferText,
    ourMethodTitle: page##ourMethodTitle,
    ourMethodText: page##ourMethodText##ourMethodText,
    contacts: Employee.fromArray(page##contacts),
  };
};

module About = {
  type t = {
    funTitle: string,
    funText: string,
    goodText: string,
    goodTitle: string,
    valueText: string,
    valueTitle: string,
    valueeText: string,
    valueIteam: string,
    stabilityText: string,
    stabilityTitle: string,
    stabilityIcons: list((string, string)),
    contactTitle: string,
    contacts: list(Employee.t),
    header: Header.t,
  };

  let make = page => {
    header: Header.make(page),
    funTitle: page##funTitle,
    funText: page##funText##funText,
    goodText: page##goodText##goodText,
    goodTitle: page##goodTitle,
    valueText: page##valueText##valueText,
    valueTitle: page##valueTitle,
    valueeText: page##valueeText,
    valueIteam: page##valueIteam##valueIteam,
    stabilityTitle: page##stabilityTitle,
    stabilityText: page##stabilityText##stabilityText,
    stabilityIcons:
      page##stabilityIcons
      ->Belt.Array.map(Assets.Image.make)
      ->Belt.List.fromArray,
    contactTitle: page##contactTitle,
    contacts: Employee.fromArray(page##contacts),
  };
};

module Opportunity = {
  type t = {
    aboutUsTitle: string,
    aboutUs: string,
    application: string,
    applicationTitle: string,
    bonusKnowledgeTitle: string,
    bonusKnowledge: string,
    contactTitle: string,
    contacts: list(Employee.t),
    header: Header.t,
    knowledgeTitle: string,
    knowledge: string,
    location: string,
    title: string,
    perksTitle: string,
    perks: string,
    roleTitle: string,
    role: string,
    technicalitiesTitle: string,
    technicalities: string,
  };

  let make = opportunity => {
    aboutUsTitle: opportunity##aboutUsTitle,
    aboutUs: opportunity##aboutUs##aboutUs,
    applicationTitle: opportunity##applicationTitle,
    application: opportunity##application##application,
    bonusKnowledgeTitle: opportunity##bonusKnowledgeTitle,
    bonusKnowledge: opportunity##bonusKnowledge##bonusKnowledge,
    contactTitle: opportunity##contactTitle,
    contacts:
      opportunity##contacts
      ->Belt.Array.map(Employee.make)
      ->Belt.List.fromArray,
    header: Header.make(opportunity),
    knowledgeTitle: opportunity##knowledgeTitle,
    knowledge: opportunity##knowledge##knowledge,
    location: opportunity##location,
    title: opportunity##title,
    perksTitle: opportunity##perksTitle,
    perks: opportunity##perks##perks,
    roleTitle: opportunity##roleTitle,
    role: opportunity##role##role,
    technicalitiesTitle: opportunity##technicalitiesTitle,
    technicalities: opportunity##technicalities##technicalities,
  };
};

module Career = {
  module Opportunity = {
    type t = {
      id: string,
      role: string,
      location: string,
      title: string,
      urlId: string,
    };
    let make = opportunity => {
      id: opportunity##id,
      role: opportunity##role##role,
      location: opportunity##location,
      title: opportunity##title,
      urlId: opportunity##urlId,
    };
  };

  type t = {
    header: Header.t,
    contacts: list(Employee.t),
    opportunities: list(Opportunity.t),
    contactTitle: string,
    openApplicationLabel: string,
    openApplicationText: string,
  };

  let make = page => {
    header: Header.make(page##contentfulSidaJobbaHosOss),
    contactTitle: page##contentfulSidaJobbaHosOss##contactTitle,
    opportunities:
      page##allContentfulAnnonser##nodes
      ->Belt.Array.map(Opportunity.make)
      ->Belt.List.fromArray,
    contacts:
      page##contentfulSidaJobbaHosOss##contacts
      ->Belt.Array.map(Employee.make)
      ->Belt.List.fromArray,
    openApplicationLabel:
      page##contentfulSidaJobbaHosOss##openApplicationLabel,
    openApplicationText:
      page##contentfulSidaJobbaHosOss##openApplicationText##openApplicationText,
  };
};

module HowWeWork = {
  type t = {
    methodTitle: string,
    methodText: string,
    sharingText: string,
    sharingTitle: string,
    teamText: string,
    teamTitle: string,
    customersText: string,
    customersTitle: string,
    hiringTitle: string,
    openApplicationText: string,
    openApplicationHeader: string,
    contactTitle: string,
    contacts: list(Employee.t),
    header: Header.t,
  };

  let make = page => {
    methodTitle: page##methodTitle,
    methodText: page##methodText##methodText,
    sharingText: page##sharingText##sharingText,
    sharingTitle: page##sharingTitle,
    teamText: page##teamText##teamText,
    teamTitle: page##teamTitle,
    customersText: page##customersText##customersText,
    customersTitle: page##customersTitle,
    hiringTitle: page##hiringTitle,
    openApplicationText: page##openApplicationText##openApplicationText,
    openApplicationHeader: page##openApplicationHeader,
    contactTitle: page##contactTitle,
    contacts: Employee.fromArray(page##contacts),
    header: Header.make(page),
  };
};

module Coworkers = {
  type t = {
    contactTitle: string,
    contacts: list(Employee.t),
    header: Header.t,
  };

  let make = page => {
    contactTitle: page##contactTitle,
    contacts: Employee.fromArray(page##contacts),
    header: Header.make(page),
  };
};

module Coworker = {
  type t = {
    name: string,
    title: string,
    why: string,
    whyTitle: string,
    phoneNumber: option(string),
    email: string,
    competence: string,
    competenceTitle: string,
    background: string,
    backgroundTitle: string,
    header: Header.t,
  };

  let make = page => {
    name: page##name,
    title: page##title,
    why: page##why##why,
    whyTitle: page##whyTitle,
    competence: page##competence##competence,
    competenceTitle: page##competenceTitle,
    background: page##background##background,
    backgroundTitle: page##backgroundTitle,
    email: page##email,
    phoneNumber:
      switch (page##phoneNumber->Js.Nullable.toOption) {
      | Some(pn) => Some(Telefonnummer.parse(pn))
      | _ => None
      },
    header: Header.make(page),
  };
};

module Offers = {
  type t = {
    intro: string,
    header: Header.t,
    contactTitle: string,
    contactSubtitle: option(string),
    contacts: list(Employee.t),
  };

  let make = page => {
    header: Header.make(page),
    intro: page##offersLeadText##offersLeadText,
    contactTitle: page##contactTitle,
    contactSubtitle: page##contactSubtitle |> Js.Nullable.toOption,
    contacts:
      page##contacts->Belt.Array.map(Employee.make)->Belt.List.fromArray,
  };
};

module Cases = {
  type t = {
    header: Header.t,
    contactTitle: string,
    contacts: list(Employee.t),
  };

  let make = page => {
    header: Header.make(page),
    contactTitle: page##contactTitle,
    contacts:
      page##contacts->Belt.Array.map(Employee.make)->Belt.List.fromArray,
  };
};

module Case = {
  module FluidImage = {
    type t = {
      url: string,
      localFile: option(Js.t({.})),
    };

    let make = headerData => {
      headerData##file##url->Js.String2.includes("empty")
        ? None
        : Some({
            url: headerData##file##url,
            localFile:
              switch (headerData##localFile->Js.Nullable.toOption) {
              | Some(local) => Some(local##childImageSharp##fluid)
              | None => None
              },
          });
    };
  };

  module Logo = {
    type t = {
      src: string,
      height: string,
      width: string,
    };

    let make = logo => {
      src: logo##localFile##publicURL,
      height: logo##file##details##image##height,
      width: logo##file##details##image##width,
    };
  };

  type t = {
    aboutCompany: string,
    aboutCompanyTitle: string,
    casePageImage: option(FluidImage.t),
    contact: option(string),
    contactTitle: option(string),
    contactSubtitle: option(string),
    contacts: list(Employee.t),
    development: string,
    developmentTitle: string,
    frameworks: option(array(string)),
    frameworksTitle: option(string),
    header: option(FluidImage.t),
    headerBgColor: string,
    introduction: string,
    introductionTitle: string,
    logo: Logo.t,
    partners: option(string),
    partnersTitle: string,
    process: string,
    processTitle: string,
    quote: option(string),
    quoteBgColor: option(string),
    quotePerson: option(string),
    quoteEmployeePosition: option(string),
    shortDescription: string,
    slug: string,
    tags: array(string),
    title: string,
  };

  let make = page => {
    aboutCompany: page##aboutCompany##aboutCompany,
    aboutCompanyTitle: page##aboutCompanyTitle,
    header: FluidImage.make(page##casePageBackgroundImage),
    casePageImage: FluidImage.make(page##casePageImage),
    contact:
      switch (page##contact->Js.Nullable.toOption) {
      | Some(c) => c##contact
      | None => None
      },
    contactTitle: page##contactTitle->Js.Nullable.toOption,
    contactSubtitle: page##contactSubtitle->Js.Nullable.toOption,
    contacts:
      page##contacts->Belt.Array.map(Employee.make)->Belt.List.fromArray,
    development: page##development##development,
    developmentTitle: page##developmentTitle,
    frameworks: page##frameworks,
    frameworksTitle: page##frameworksTitle,
    headerBgColor: page##headerBgColor,
    introduction: page##introduction##introduction,
    introductionTitle: page##introductionTitle,
    logo: Logo.make(page##logo),
    partners:
      switch (page##partners->Js.Nullable.toOption) {
      | Some(p) => p##partners
      | None => None
      },
    partnersTitle: page##partnersTitle,
    process: page##process##process,
    processTitle: page##processTitle,
    quote:
      switch (page##quote->Js.Nullable.toOption) {
      | Some(q) => q##quote
      | None => None
      },
    quoteBgColor: page##quoteBgColor->Js.Nullable.toOption,
    quotePerson: page##quotePerson->Js.Nullable.toOption,
    quoteEmployeePosition: page##quoteEmployeePosition->Js.Nullable.toOption,
    shortDescription: page##shortDescription,
    slug: page##slug,
    tags: page##tags,
    title: page##title,
  };
};

module Blog = {
  module Tag = {
    type t = {name: string};

    let make = tag => {
      switch (tag |> Js.Nullable.toOption) {
      | Some(tag) => Some({name: tag##name})
      | None => None
      };
    };
  };

  module Author = {
    type t = {
      bio: option(string),
      name: string,
      profileImage: string,
    };

    let make = author => {
      bio: author##bio,
      name: author##name,
      profileImage: author##profile_image,
    };
  };

  module Settings = {
    type t = {cover: string};

    let make = settings => {cover: settings##cover_image};
  };

  module Short = {
    type post = {
      author: Author.t,
      content: string,
      featureImage: string,
      publishedAt: string,
      slug: string,
      title: string,
    };

    type t = {
      posts: list(post),
      settings: Settings.t,
    };

    let make = (~posts, ~settings) => {
      posts:
        posts
        ->Belt.List.fromArray
        ->Belt.List.map(item =>
            {
              author: Author.make(item##primary_author),
              content: item##excerpt,
              title: item##title,
              publishedAt: item##published_at,
              slug: item##slug,
              featureImage: item##feature_image,
            }
          ),
      settings: Settings.make(settings),
    };
  };

  type t = {
    author: Author.t,
    content: string,
    featureImage: string,
    publishedAt: string,
    slug: string,
    tag: option(Tag.t),
    title: string,
  };

  let make = item => {
    author: Author.make(item##primary_author),
    content: item##html,
    featureImage: item##feature_image,
    publishedAt: item##published_at,
    slug: item##slug,
    tag: Tag.make(item##primary_tag),
    title: item##title,
  };
};
