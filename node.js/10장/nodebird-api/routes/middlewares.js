const jwt = require(`jsonwebtoken`);
const RateLimit = require('express-rate-limit');

exports.isLoggedIn = (req, res, next) => {
    if (req.isAuthenticated()) {
        next();
    } else {
        res.status(403).send('로그인 필요');
    }
};

exports.isNotLoggedIn = (req, res, next) => {
    if (!req.isAuthenticated()) {
        next();
    } else {
        const message = encodeURIComponent('로그인한 상태입니다.');
        res.redirect('/?error=${message}');
    }
}

exports.verifyToken = (req, res, next) => {
    try {
        req.decoded = jwt.verify(req.headers.authorization, process.env.JWT_SECRET);
        return next();
    } catch (error) {
        if (error.name === 'TokenExpiredError') {//유효기간 지난 경우
            return res.status(419).json({
                code: 419,
                message: '토큰이 만료되었습니다.'
            })
        }
        return res.status(401).json({//토큰의 비밀키가 일치하지 않는 경우
            code: 401,
            messge: '유효하지 않은 토큰입니다.',
        })
    }
}


exports.apiLimiter = RateLimit({
    windowMs: 60 * 1000, // 1분 기준시간
    max: 10,//허용횟수
    delayMs: 0,
    handler(req, res) {//제한초과시 콜백함수
        res.status(this.statusCode).json({
            code: this.statusCode, // 기본값 429
            message: '1분에 한 번만 요청할 수 있습니다.',
        });
    },
});

exports.deprecated = (req, res) => {//사용하면 안되는 라우터
    res.status(410).json({
        code: 410,
        message: '새로운 버전이 나왔습니다. 새로운 버전을 사용하세요'
    })
}