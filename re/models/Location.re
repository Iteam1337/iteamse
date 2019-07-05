type t = [ | `All | `Gothenburg | `Stockholm];

let asList = [`All, `Stockholm, `Gothenburg];

let fromString =
  fun
  | "Stockholm" => `Stockholm
  | _ => `Gothenburg;

let toString =
  fun
  | `All => "Alla"
  | `Gothenburg => {js|Göteborg|js}
  | `Stockholm => "Stockholm";
