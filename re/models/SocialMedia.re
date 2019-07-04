type company = [
  | `Facebook
  | `Instagram
  | `LinkedIn
  | `YouTube
  | `MyNewsDesk
  | `Unknown
];

type t = {
  company,
  icon: string,
  name: string,
  href: string,
};

let toType =
  fun
  | "icon-facebook" => `Facebook
  | "icon-instagram" => `Instagram
  | "icon-linkedin" => `LinkedIn
  | "icon-youtube" => `YouTube
  | "icon-mynewsdesk" => `MyNewsDesk
  | _ => `Unknown;

let toName =
  fun
  | `Facebook => "Facebook"
  | `Instagram => "Instagram"
  | `LinkedIn => "LinkedIn"
  | `YouTube => "YouTube"
  | `MyNewsDesk => "MyNewsDesk"
  | `Unknown => "";

let toHref =
  fun
  | `Facebook => "https://www.facebook.com/iteam1337/"
  | `Instagram => "https://instagram.com/iteam1337"
  | `LinkedIn => "https://www.linkedin.com/company/270569/"
  | `YouTube => "https://www.youtube.com/channel/UCU2TdLZ7p0jEuuGUxaod4lw"
  | `MyNewsDesk => "http://www.mynewsdesk.com/se/iteam"
  | `Unknown => "";

let make = icon => {
  let company = toType(icon##name);

  {
    company,
    icon: icon##publicURL,
    name: toName(company),
    href: toHref(company),
  };
};
