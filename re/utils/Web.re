open Webapi.Dom;

module ClassName = {
  let add = (el, className) => {
    el |> Element.classList |> DomTokenList.add(className);
  };

  let remove = (el, className) => {
    el |> Element.classList |> DomTokenList.remove(className);
  };
};

module Document = {
  let element = document |> Document.documentElement;
};

module Keyboard = {
  let addKeyUpListener = fn => {
    document
    |> Webapi.Dom.Document.asEventTarget
    |> EventTarget.addKeyUpEventListener(fn);
  };

  let removeKeyUpListener = fn => {
    document
    |> Webapi.Dom.Document.asEventTarget
    |> EventTarget.removeKeyUpEventListener(fn);
  };
};
