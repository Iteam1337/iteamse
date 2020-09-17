# Iteam.se

[![Build Status](https://travis-ci.com/Iteam1337/iteamse-poc.svg?branch=master)](https://travis-ci.com/Iteam1337/gatsby-contentful-reason-poc)

This is an updated version of [iteam.se](https://iteam.se/) built on top of Gatsby with ReasonML. It is currently in alpha stage, with some functionality missing. The concept is promising and means that we can scrap our custom GraphQL API that is currently being used. Since the site will be built at compile time it'll also be even faster and the static files could be deployed easily.

## Prerequisites

Environment variables are needed in a `.env.development` with:

```
CONTENTFUL_SPACE=
CONTENTFUL_ACCESS_TOKEN=
```

Values are available in LastPass.

## Get started

```
npm install
npm run start
npm run dev (in another terminal)
```

Open http://localhost:8000

## Deployment & CI

Every push (and therefore every merge to master) gets built and deployed automatically at [Zeit](https://zeit.co). Every opened pull request also gets built and deployed automatically under a separate alias for easy reviewing.
