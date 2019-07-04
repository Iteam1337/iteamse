import React from 'react'
import { graphql, useStaticQuery } from 'gatsby'
import Career from '../../lib/js/re/pages/Career'
import '../index.css'

export default () => {
  const data = useStaticQuery(graphql`
    query Career {
      contentfulSidaJobbaHosOss {
        headerImage {
          title
          file {
            url
          }
        }
        headerText1
        headerTextBgColor
        hiringTitle
        contactTitle
        openApplicationLabel
        openApplicationText {
          openApplicationText
        }
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
        }
      }
    }
  `)

  return <Career data={data.contentfulSidaJobbaHosOss} />
}
