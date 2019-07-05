import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import About from '../../lib/js/re/pages/About'
import Layout from '../Layout'

export default () => {
  const data = useStaticQuery(graphql`
    query AboutUs {
      contentfulSidaOmOss {
        headerTextBgColor
        headerText1
        headerText2
        headerImage {
          file {
            url
          }
        }
        funTitle
        funText {
          funText
        }
        goodText {
          goodText
        }
        goodTitle
        imageBleed {
          file {
            url
          }
        }
        valueText {
          valueText
        }
        valueTitle
        valueeText
        valueIteam {
          valueIteam
        }
        stabilityTitle
        stabilityText {
          stabilityText
        }
        stabilityIcons {
          file {
            url
          }
        }
        contactTitle
        contacts {
          avatar {
            file {
              url
            }
          }
          email
          name
          short
          title
          phoneNumber
        }
      }
      illustrationFun: file(relativePath: { eq: "illustration-fun.svg" }) {
        publicURL
      }
    }
  `)

  return (
    <Layout>
      <About
        data={data.contentfulSidaOmOss}
        illustrationFun={data.illustrationFun.publicURL}
      />
    </Layout>
  )
}
