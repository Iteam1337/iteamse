[@react.component]
let make = (~url, ~children, ~color as c=`CornflowerBlue) => {
  <a
    className=Css.(
      merge([
        "border-b-2 border-solid border-current text-lg",
        Theme.Colors.textFromType(c),
      ])
    )
    href=url>
    children
  </a>;
};
