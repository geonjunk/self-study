import React from 'react';
import './About.css'
function About(props){
    console.log(props);
    return(
        <div className="about__container">
            <span>
                "Freedom is the freedom to say that two plus two make four"
            </span>
            <span>George Gak 2017</span>
        </div>
    );
}

export default About;