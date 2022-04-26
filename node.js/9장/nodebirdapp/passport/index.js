const passport = require(`passport`);
const local = require(`./localStrategy`);
const kakao = require(`./kakaoStrategy`);
const User = require(`../models/user`);

module.exports = () => {
    passport.serializeUser((user, done) => {
        done(null, user.id);
    });

    passport.deserializeUser((id, done) => {//include로 join하여 팔로우 팔로잉 가져오기
        User.findOne({ where: { id },
            include:[{
            model:User,
            attributes:['id','nick'],
            as:'Followers',},{
                model:User,
                attributes:['id','nick'],
                as:'Followings',
            }],
        })
            .then(user => done(null, user))
            .catch(err => done(err));
    });

    local();
    kakao();
}