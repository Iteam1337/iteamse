import React from 'react'
import Layout from '../Layout'
import { Helmet } from 'react-helmet'
import md5 from 'md5'
import { graphql } from 'gatsby'
import Coworker from '../../lib/js/re/pages/Coworker'

export default ({ data }) => {
  return (
    <Layout>
      <Helmet>
        <html lang="sv" />
        <title>{`Iteam | Medarbetare - ${data.contentfulKollegor.name}`}</title>
        <meta
          property="og:title"
          content={`Iteam | Medarbetare - ${data.contentfulKollegor.name}`}
        />
        <meta
          property="og:image"
          content={
            Boolean(data.contentfulKollegor.avatar)
              ? data.contentfulKollegor.avatar.localFile.publicURL
              : `https://www.gravatar.com/avatar/${md5(
                  data.contentfulKollegor.email
                )}?s=300`
          }
        />
      </Helmet>
      <Coworker data={data.contentfulKollegor} />
    </Layout>
  )
}

export const query = graphql`
  query Coworker($short: String!) {
    contentfulKollegor(short: { eq: $short }) {
      name
      why {
        why
      }
      whyTitle
      title
      phoneNumber
      email
      competenceTitle
      competence {
        competence
      }
      backgroundTitle
      background {
        background
      }
      headerTextBgColor
      headerImage {
        file {
          url
        }
        localFile {
          childImageSharp {
            fluid(maxWidth: 1920, quality: 95) {
              ...GatsbyImageSharpFluid
            }
          }
        }
      }
      avatar {
        localFile {
          publicURL
        }
      }
    }
  }
`
