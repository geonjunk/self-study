import React from 'react';
import PropTypes from 'prop-types';
import './Movie.css'
import {Link} from 'react-router-dom';

function Movie({title,year,summary,poster,genres}){
    return (
        <div className="movie">
            <Link to={
                {
                    pathname : '/movie-detail',
                    state : {year,title,summary,poster,genres},
                }}>
            <img title={title} alt={title} src={poster}/>
            <div className='movie__data'>
                <h3 className="movie__title">{title}</h3>
                <h5 className="movie__year">{year}</h5>
                <p className="movie__summary">{summary.slice(0,180)}..</p>
                <ul className="movie__genres">
                    {genres.map((genre,index)=>{
                        return (<li className="movie__genre" key={index}>{genre}</li>);
                    })}
                </ul>
            </div>
            </Link>
        </div>
    );
    
}
Movie.propTypes={
    year:PropTypes.number.isRequired,
    title:PropTypes.string.isRequired,
    summary:PropTypes.string.isRequired,
    poster:PropTypes.string.isRequired,
    genres:PropTypes.arrayOf(PropTypes.string).isRequired,
};


export default Movie;