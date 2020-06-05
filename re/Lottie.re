[@bs.deriving jsConverter]
type animationConfig = {
  loop: bool,
  autoplay: bool,
  animationData: Js.Json.t,
};

[@bs.module "react-lottie"] [@react.component]
external make: (~options: animationConfig) => React.element = "default";