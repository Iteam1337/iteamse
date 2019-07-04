module Colors = {
  type t = [ | `Aquamarine | `Concrete | `CornflowerBlue | `RadicalRed];

  let fromType =
    fun
    | `Aquamarine => "bg-aquamarine"
    | `Concrete => "bg-concrete"
    | `CornflowerBlue => "bg-cornflower-blue text-white"
    | `RadicalRed => "bg-radical-red text-white";

  let fromHex =
    fun
    | "#FF405F" => `RadicalRed
    | _ => `Concrete;
};

module Breakpoints = {
  let fromType =
    fun
    | `Mobile => "(max-width: 480px)"
    | `Tablet => "(max-width: 1024px)"
    | `Desktop => "(min-width: 1025px)";
};
