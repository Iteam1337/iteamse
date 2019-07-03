module Colors = {
  let fromType =
    fun
    | `Aquamarine => `hex("54FBAC")
    | `Concrete => `hex("F3F2F2")
    | `CornflowerBlue => `hex("668CFF")
    | `RadicalRed => `hex("FF3B5C");
};

module Breakpoints = {
  let fromType =
    fun
    | `Mobile => "(max-width: 480px)"
    | `Tablet => "(max-width: 1024px)"
    | `Desktop => "(min-width: 1025px)";
};
