module Colors = {
  type t = [
    | `Aquamarine
    | `Concrete
    | `CornflowerBlue
    | `RadicalRed
    | `White
  ];

  let fromType =
    fun
    | `Aquamarine => "bg-aquamarine text-black"
    | `Concrete => "bg-concrete text-black"
    | `CornflowerBlue => "bg-cornflower-blue text-white"
    | `RadicalRed => "bg-radical-red text-white"
    | `White => "bg-transparent text-black";

  let textFromType =
    fun
    | `Aquamarine => "text-aquamarine"
    | `Concrete => "text-concrete"
    | `CornflowerBlue => "text-cornflower-blue"
    | `RadicalRed => "text-radical-red"
    | `White => "text-white";

  let fromHex =
    fun
    | "red"
    | "#FF405F" => `RadicalRed
    | "green"
    | "#54FBAC" => `Aquamarine
    | "blue"
    | "#668CFF" => `CornflowerBlue
    | "white"
    | "#FFFFFF" => `White
    | _ => `Concrete;
};

module Breakpoints = {
  let fromType =
    fun
    | `Mobile => "(max-width: 480px)"
    | `Tablet => "(max-width: 1024px)"
    | `Desktop => "(min-width: 1025px)";
};
