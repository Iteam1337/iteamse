[@react.component]
let make = (~url) => {
  <div className="fixed right-0 bottom-0 w-sm h-full border-0">
    <iframe
      width="100%"
      height="100%"
      title="Closr Chatbot - iteam.se"
      src=url
    />
  </div>;
};

let default = make;