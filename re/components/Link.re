[@react.component]
let make = (~url, ~children, ~color as c=`CornflowerBlue) => {
  <Gatsby.Link
    className={
      Some(
        Css.(
          merge([
            "border-b-2 border-solid border-current text-lg",
            Theme.Colors.textFromType(c),
          ])
        ),
      )
    }
    _to=url>
    children
  </Gatsby.Link>;
};
